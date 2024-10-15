# Red-Black Tree Implementation in C

## Introduction

A Red-Black Tree is a kind of self-balancing binary search tree. Each node of the binary tree has an extra bit, often interpreted as the color (red or black) of the node. These color bits are used to ensure the tree remains approximately balanced during insertions and deletions.

Balance is preserved by painting each node of the tree with one of two colors (typically called ‘red’ or ‘black’) in a way that satisfies certain properties. These properties collectively constrain how unbalanced the tree can become in the worst case. When the tree is modified, the new tree is rearranged and repainted to restore the coloring properties. The properties are designed to ensure that this rearranging and recoloring can be performed efficiently.

The rebalancing is not perfect but guarantees searching in O(log n) time, where n is the number of nodes in the tree. The insertion and deletion operations, along with the tree rearrangement and recoloring, are also performed in O(log n). Tracking the color of each node requires only 1 bit of information per node because there are only two colors. The tree does not contain any other data specific to its being a Red-Black Tree, so its memory footprint is almost identical to a classic (uncolored) binary search tree. In many cases, the additional bit of information can be stored at no additional memory cost.

## Requirements

Here are the requirements for the Red-Black Tree project:

1. Each node is either red or black.
2. The root is black. (This rule is sometimes omitted; since the root can always be changed from red to black, this rule has little effect on analysis.)
3. All leaves (NIL) are black.
4. If a node is red, then both its children are black.
5. Every path from a given node to any of its descendant NIL nodes contains the same number of black nodes. 

Some definitions:
- The number of black nodes from the root to a node is the node's black depth.
- The uniform number of black nodes in all paths from root to the leaves is called the black-height of the Red-Black Tree.

## Operations Implemented

The following operations are implemented in the Red-Black Tree:

- **Insertion**: Add a new node while maintaining the properties of the Red-Black Tree.
- **Deletion**: Remove a node from the tree while preserving balance.
- **Search**: Find a node with a specified value.
- **Find Min**: Retrieve the minimum value in the tree.
- **Delete Min**: Remove the node with the minimum value.
- **Find Max**: Retrieve the maximum value in the tree.
- **Delete Max**: Remove the node with the maximum value.
- **Inorder Traversal**: Display the values in the tree in ascending order.
- **Display Tree**: Visual representation of the tree structure.

## Code Structure

The code is structured into three files:

1. **`main.c`**: Contains the main function and user interface for interacting with the Red-Black Tree.
2. **`red_black_tree.c`**: Implements the core functionality of the Red-Black Tree, including the operations listed above.
3. **`main.h`**: Header file containing the definitions and function prototypes.

### Important Variables
- **x, y, z**: These are temporary variables used in rotation and insertion functions. Specifically:
  - **x**: Typically represents the node being manipulated (either rotated or inserted).
  - **y**: Often used as the parent node during insertion and rebalancing.
  - **z**: Generally represents the newly inserted node that may need rebalancing.

## Installation

1. Clone the repository or download the project files.
2. Open a terminal and navigate to the project directory.
3. Compile the project using the following command:

   ```bash
   gcc *.c -o red_black_tree

   ./red_black_tree

    1. Insert
    2. Delete
    3. Search
    4. Find Min
    5. Delete Min
    6. Find Max
    7. Delete Max
    8. Display Tree
    9. Inorder Traversal
    0. Exit
    Enter your choice: 1
    Enter value to insert: 15
