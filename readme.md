# CS225 Final Project

## Team Members: zaali2, aswar3, shyammt2 , ...

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







