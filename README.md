# Sequence-Alignment
A fast &amp; cache-friendly implementation of the Needleman–Wunsch algorithm for sequence alignment

## To Build:
Use the GNU Make utility along with the Makefile in the root directory. This builds an executable by the name of ```align```

```
git clone https://github.com/tazzaoui/Sequence-Alignment.git && cd Sequence-Alignment && make
```

## To Run:
The program expects two ASCII strings separated by a new line as input. It's typically more convenient to place these strings in a file and use standard input redirection. Examples files are included in the ```Examples``` directory.

## Example Usage:
```
$ ./align < Examples/10.txt
t -
g -
g a
t c
t a
g g
g g
g c
a g
```
