import matplotlib.pyplot as plt
from scipy.spatial import ConvexHull
import sys

# take file path of in.txt and out.txt as input from cmd line
if len(sys.argv) != 3:
    print("Error: Invalid number of arguments")
    print("Usage: python convexHullChecker.py <input_file_path> <output_file_path>")
    exit(0)

input_file_path = sys.argv[1]
output_file_path = sys.argv[2]


# Read points from the in.txt file
with open(input_file_path, "r") as f:
    n = int(f.readline())
    in_points = [tuple(map(float, line.strip().split())) for line in f]

# Extract x and y coordinates from input points
in_x_coords = [point[0] for point in in_points]
in_y_coords = [point[1] for point in in_points]

# Compute the convex hull of the input points
input_convex_hull = ConvexHull(in_points)

convexHull_out = []


# print("Convex Hull of Input Points:")
for i in input_convex_hull.vertices:
    # x y 
    convexHull_out.append(tuple([in_points[i][0], in_points[i][1]]))

with open("output_code.txt", "w") as f:
    for i in input_convex_hull.vertices:
        f.write(str(in_points[i][0]) + " " + str(in_points[i][1]) + "\n")

with open(output_file_path, "r") as f:
    out_points = [tuple(map(float, line.strip().split())) for line in f]


if len(out_points) != len(convexHull_out):
    print("Error: Number of fence points is not optimal")
    exit(0)

for i in range(len(out_points)):
    if out_points[i] not in convexHull_out:
        print("Error: Fence point "+ str(out_points[i]) +" is not optimal")
        exit(0)

print("!!!!!!!!!!!!!!All OKAY!!!!!!!!!!!")

# Create a scatter plot of input points and convex hull
plt.figure(figsize=(8, 6))
plt.scatter(in_x_coords, in_y_coords, color='blue', label='Coordinates of Trees')
plt.plot([in_x_coords[i] for i in input_convex_hull.vertices] + [in_x_coords[input_convex_hull.vertices[0]]],
         [in_y_coords[i] for i in input_convex_hull.vertices] + [in_y_coords[input_convex_hull.vertices[0]]],
         linestyle='solid', color='green', label='Optimal Fence')
plt.xlabel('X Coordinate')
plt.ylabel('Y Coordinate')
plt.title('Visualization of Trees and Fence')
plt.legend()
plt.grid(True)
plt.show()
