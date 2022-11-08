# CS225 Final Project

## Team Members: zaali2, aswar3, shyammt2 , bchang

## Introduction

The goal of our project is to create a simple “related topics” recommendation tool. Given two topics/Wikipedia page titles, we will use the Floyd-Warshall algorithm to find the shortest path between them. From there, we will look at the middle node on the path because it should be related to both topics. Ideally, the middle page would be something that a human would think of when given the two initial topics as prompts (e.g. food and Italy might output something like pasta). This tool could be used to identify topics that might interest a user based on their past search history (similar to the “you might also like…” recommendation algorithms on Netflix or Amazon). 

## Installation
To be added

## Description
### Dataset Acquisition
This project will focus on using the “English Wikipedia hyperlink network” dataset from the Stanford Large Network Dataset Collection. 
https://snap.stanford.edu/data/enwiki-2013.html
### Data Format
The “English Wikipedia hyperlink network” is a directed graph where an edge exists from i to j if a hyperlink exists on page i to page j. 
The data set is a downloadable 1.56 GB text file. Each line has a pair of two node IDs. The first index is the “from” node and the second index is the “to” node. The graph has 4,203,323 nodes and 101,311,614 edges, with a corresponding csv file with the titles of each page. The CSV file contains an integer node ID and a string title on each line. Because of the size of the graph, we will trim the number of nodes to the top 100,000 Wikipedia pages with the highest degree centrality by performing a breadth-first traversal and calculating the out-degree and in-degree of each node. We will then use the PageRank algorithm (which should yield more accurate results than just using degree centrality) to further cut down the number of nodes to 25,000. 
### Data Correction
As mentioned in the data format section, we plan on trimming the number of nodes from 4,203,323 to just 25,000 with the highest degree centrality. We will also clean up the page titles by replacing special characters like \u80 to €. To parse the data, we will iterate through each line of the graph data file, checking that there are two valid integer indices on each line and constructing an adjacency matrix in the process. If either of the indices are invalid (i.e. don’t have a corresponding title or correspond to a node that we cut from the graph when taking a subset), we will ignore that edge. 
### Data Storage
We will utilize an adjacency matrix to store the graph. The elements of the matrix will indicate whether an edge connects a pair of vertices in the graph. Since an adjacency matrix will have V columns and V rows, the space complexity of the matrix will be O(V2). From the Floyd-Warshall algorithm, we will also store a 2D matrix with the length of the shortest paths between each node and a 2D matrix that stores the predecessor of each node on the shortest path. Both of these matrixes will be O(V2). 

The runtime complexity to check whether an edge exists is O(1). A dictionary may also be used to map node IDs to their Wikipedia page title (O(V)).
### Graph Algorithms
To trim our dataset, we would use BFS to calculate the degree centrality of each node to trim down the total number of nodes from 4 million to 100,000. Finding the number of edges of each node can be done in constant time, so the runtime for the BFS would be O(V). We would then use PageRank to rank the 100,000 remaining nodes in our graph, taking the top 25,000 and trimming the rest. PageRank runs in O(V + E) time and would likely take too long if we ran it on the initial data set with 4 million nodes and 100 million edges.

After converting the titles to node IDs, we will use the Floyd-Warshall algorithm on our graph with no weights to create a matrix that stores the shortest paths between all pairs of nodes. The Floyd-Warshall algorithm takes a directed graph matrix as an input, outputting a 2D matrix with the lengths of the shortest paths between all pairs of nodes and a 2D matrix that stores the predecessor of each node on the shortest paths. 

The expected inputs for our main program are the titles of two Wikipedia pages. Using the stored path matrices from the Floyd-Warshall algorithm we will be able to output the distance between the two pages in constant time (accessing a stored value in the array) and the full path between the two pages in O(path length) time. The full path is printed by recursively finding the parent of each node in the path. Although the shortest path could be the entire set of vertexes if the graph were a straight line in the worst case, the actual length of the path will likely be relatively short given the highly interlinked nature of Wikipedia articles, meaning that the runtime for retracing the path will essentially be constant. 

The expected output from these two Wikipedia pages would be the middle node on the path that should be most related to both pages. To visualize the output, we will display the link that represents the middle node topic along with the full path between the two nodes. The estimated Big O efficiency of the algorithm that will be used is O(V2). In addition to the O(V^2) adjacency matrix, we would have to store the “parent” array and the output matrix which are both O(V^2)






