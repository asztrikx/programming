# Coding
  ## Use camelCase
  > The matter is that the codes should not be different for the ease of reading  
  > It can be better as it creates shorter variable names  
  ## Do not shorten calculations
  > It is easier to see how you got to the number in eg. indexing, array size  
  ```c++
  array[ordinalNumber - 1 + 1]; //access right next number to ordinalNumber
  ```
  ## End array variable names with S
  > It signs that we have a collection of something  
  > You can use multiple S if structure requires it  
  > Do not use ES when it is grammatically correct as it creates inconsistent naming  
  > You can skip it for conventional names eg. matrix, graph  
  ```c++
  vector<int> childS; //not children
  vector<vector<int>> heightSS;
  vector<int> heightS = heightSS[0]; //notice the decrement in the number of 'S'-s
  vector<vector<int>> matrix;
  vector<vector<int>> graph;
  ```
  ## Segmentation
  //[R] TODO (Input, out-, process)
  ## Use `,` even after the last item in a listing
  > On a multiline listing it's easy to miss out the line ending `,`  
  ```c++
  vector<int> a = {
    5,
    4,
    3 //Syntax Error
    2
  };
  ```
  ```c++
  vector<int> a = {
    5,
    4,
    3,
    2,
  };
  ```
# Folder
  //[R] TODO (1_cpp.cpp)
  //[R] Clone mester
# Math
> log = log2  
