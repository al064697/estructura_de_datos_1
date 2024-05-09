import os  # Import the os module for operating system related operations
from graphviz import Digraph  # Import the Digraph class from the graphviz module for creating and rendering graphs

class Node:
    def __init__(self, value):  # Constructor method of the Node class
        """
        Initializes a new node with the specified value.

        Parameters:
            - value: The value to be assigned to the node.

        Returns:
            Nothing, but initializes a new node with the given value and no children.
        """
        
        self.value = value  # Initialize the value of the node with the given value
        self.left = None    # Initialize the left child as None
        self.right = None   # Initialize the right child as None

def preorder_traversal(root):
    """
    Performs a preorder traversal of the binary tree.

    Parameters:
        - root: The root node of the tree.

    Returns:
        Nothing, but prints the values of the nodes in preorder.
    """
    if root:
        print(root.value, end=" ")  # Print the value of the current node
        preorder_traversal(root.left)  # Traverse the left subtree recursively
        preorder_traversal(root.right)  # Traverse the right subtree recursively

def add_node(root, path, value):
    """
    Adds a new node to the binary tree following a given path.

    Parameters:
        - root: The root node of the tree.
        - path: The path to reach the new node. It can contain 'L' to go to the left child or 'R' to go to the right child.
        - value: The value of the new node.

    Returns:
        Nothing, but adds a new node to the binary tree.
    """
    node = root
    for direction in path:
        if direction == 'L':
            if node.left is None:
                node.left = Node(None)  # Create a new node with value None if the left child does not exist
            node = node.left
        else:  # direction == 'R'
            if node.right is None:
                node.right = Node(None)  # Create a new node with value None if the right child does not exist
            node = node.right
    node.value = value  # Assign the value to the created node

def add_edges(graph, node, parent=None):
    """
    Adds the edges to the graph to visualize the binary tree.

    Parameters:
        - graph: The Digraph object for the graph.
        - node: The current node of the tree.
        - parent: The parent node of the current node.

    Returns:
        Nothing, but adds the edges to the graph to visualize the binary tree.
    """
    if node:
        if parent:
            graph.edge(str(parent.value), str(node.value))  # Add an edge from the parent node to the current node in the graph
        add_edges(graph, node.left, node)  # Add the edges for the left subtree recursively
        add_edges(graph, node.right, node)  # Add the edges for the right subtree recursively

def draw_tree(root, filename):
    """
    Draws the binary tree and saves it to a file.

    Parameters:
        - root: The root node of the binary tree.
        - filename: The name of the output file.

    Returns:
        Nothing, but draws the binary tree and saves it to a file.
    """
    graph = Digraph()  # Create a new Digraph object for the graph
    add_edges(graph, root)  # Add the edges to the graph based on the binary tree
    graph.render(filename, view=True)  # Render the graph to a file with the specified name

# Request the user to input the values
input_values = input("Please enter the values for the nodes, separated by spaces: ")

# Split the user input into a list of values
values = input_values.split()

# Create the root node with the first value provided by the user
root = Node(values[0])  # Create the root node with the first value provided by the user

# List of directions to add nodes
paths = ['L', 'R', 'LL', 'LR', 'RL', 'RR', 'LLL', 'LLR', 'LRL', 'LRR', 'RLL', 'RLR', 'RRL', 'RRR', 'LLLL', 'LLLR', 'LLRL', 'LLRR', 'LRLL', 'LRLR', 'LRRR', 'RLLL', 'RLLR', 'RLRL']

# Iterate over the paths and values and add nodes to the tree
for path, value in zip(paths, values[1:]):  # Start from the second value as the first one was used for the root node
    add_node(root, path, value)

print("Preorder traversal:")
preorder_traversal(root)  # Perform the preorder traversal of the tree and print it

output_dir = 'ejercicio3.2'  # Output directory to save the output file
os.makedirs(output_dir, exist_ok=True)  # Create the output directory if it doesn't exist

draw_tree(root, os.path.join(output_dir, 'Digraph.gv'))  # Draw the tree and save it to a file in the output directory