#### git

##### reset 

> git reset \<mode\> \<commit\>

<mode> can be

- *---soft* doesn't touch anything, just moves the head to the \<commit\>
- *---mixed* (the default) only touches the index i.e. undo add/mark for commit
- *---hard* reverts both the index and the working tree to the \<commit\> i.e. total undo!

##### timestamp spec

> branch@{"any date format"}

##### detach head

> git checkout *timestamp-spec*

##### change default push mode

> git config --global push.default *mode*

- *nothing*
- *matching* - all branches having the same name in both ends (default)
- *upstream* - the current branch to its upstream branch
- *simple* - same as *upstream* but only if name is the same
- *current* - the current branch to a branch of the same name

##### external tools

> git config --global mergetool.p4merge.path *path*

> git config --global merge.tool p4merge

##### ref specs

*r1..r2* equiv to *^r1 r2* - comits reachable from r2 but not r1 aka set difference

*r1...r2* equiv *r1 r2 --not $(git merge-base --all r1 r2)* - commits reachable from either r1 or r2 but not both aka symmetric difference

##### p4 git

http://answers.perforce.com/articles/KB_Article/Git-P4
http://ericlathrop.com/2012/12/how-to-set-up-git-p4-in-windows/
http://git-scm.com/docs/git-p4

##### rebase

- is done in the branch and that branch is applied on top of master
- on master u can do a fast-forward merge to sync up

before:
```
              A---B---C topic
             /
    D---E---F---G master
```

after:
```
                  A'--B'--C' topic
                 /
    D---E---F---G master
```
