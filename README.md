# Grep-C-Implementation
- Returns number of searched word. 
- Writes the lines containing the searched word to the output file.
## How to Compile:
`gcc grepFile.c -o grepFile`
## How to Run:
`./grepFile [textFileName] [searchedWord]`
## Sample:
1) `gcc grepFile.c -o grepFile`<br>
2) `gcc ./grepFile sample.txt deep`

**Terminal Output:** The word (deep) exists "5" time/times in the text.
<br>**Output File Content:**<br>
```   
      Line '2' has 'deep' in it.
      Line '3' has 'deep' in it.
      Line '5' has 'deep' in it.
      Line '8' has 'deep' in it.
      Line '10' has 'deep' in it. 
 ```
