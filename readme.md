# CS225 Final Project

## Team Members: zaali2, aswar3, shyammt2 , bchang

## Installation
The first step in the installation of this project is to create a folder on the user's local computer 
that contains the provided CS225 Dockerfile and .devcontainer folder with the "devcontainer" JSON file inside of 
it to duplicate the CS225 environment. The user must now run the following command in this newly created folder: 
git clone https://github.com/zayaanali/cs225-final-project.git
<br>Next, navigate into the newly cloned folder in the terminal that contains the source code from the git repository by running the following:
cd cs225-final-project
Create a new folder titled "data" by running the following after having completed the previous step:
mkdir data
<br>Download the two zip files at the following link: [Link to these 2 zip files](https://snap.stanford.edu/data/enwiki-2013.html)<br>
Drag the downloaded files titled "wikidata.txt" and "enwiki-2013-names.txt" into this newly created "data" folder.

## How to Build
Once the installation is complete, ensure that you are inside the "cs225-final-project" directory in your terminal. Then run the following commands:<br>
mkdir build<br>
cd build<br>
cmake ..<br>
Now that the build files have been created, the first step is to run the data parsing and preprocessing commands in the same order as follows:<br>
make<br>
./filter_data<br>
./filter_edges<br>
./filter_titles<br>
./bfs_trim<br>
./brandes<br>
To verify that these steps have been completed properly, check the "data" folder that was created and verify that the following files have been added to this folder:<br>
"filteredwiki.txt", "filteredadj.txt", "filteredtitles.txt", "finaladj.txt", "finaltitles.txt", "betweenness.txt"<br>
Warning: For these data parsing steps, the runtime is quite long so to save time, the parsed files titled "finaladj.txt", "finaltitles.txt", and "betweenness.txt" are also provided at this link (these 3 are the only files necessary to run the main algorithms in this program) and can be directly downloaded and placed into the "data" folder: [Link to these 3 data files](https://drive.google.com/drive/folders/1D4qHG6QAGv98keLUF5j7drPEF9_2byoq?usp=sharing)<br>
Next, to find a shared Wikipedia page output for two input Wikipedia page indexes, run the following:
./related_topics_two_inputs topic1 topic2 <br>
Note: topic1 and topic2 are strings that the user can select by opening the "finaltitles.txt" in the "data" folder. For example, a user input of<br>
./related_topics_two_inputs "Italy" "Food"
<br>will yield a result of "Emilia-Romagna". This is a region in Italy known for its culinary cuisine.
<br>NEED TO ADD STRONGLY CONNECTED COMPONENTS HERE

## Testing
The code provides a wide variety of testing for the various functions and algorithms utilized within the program. To build and run the test suite, run the following commands:<br>
make test<br>
./test<br>
The tests being ran along with the sample .txt files that are being used as the testing input files can be found within the "tests" folder in the main directory, "cs225-final-project".

## Description




