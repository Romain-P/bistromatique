# Bistromatique
Clone this project with `git clone https://github.com/romain-p/bistromatique.git`
##### Branch System
You need to keep your master branch clean, by clean I mean without any changes, like that you can create at any time a branch from your master. Each time, that you want to commit a bug or a feature, you need to create a branch for it, which will be a copy of your master branch.   
When you do a pull request on a branch, you can continue to work on another branch and make another pull request on this other branch. 
* Create a new branch ? `git checkout -b [branch] && git push origin [branch]`
* Goto another existing branch ? `git checkout [branch]`  
* Merge a given branch into the current one ? `git rebase [branch]` or `git merge [branch]` *note that rebase is a cleaner way*
* Resolve conflicts while merging? `git mergetool` *+ finally add and commit files after resolved your conflicts*
* Remove a branch ? `git checkout -D [branch]`

**Push, Add, Commit** and some other commands will operate on the branch you're currently on. To know on which branch you're currently on, just write the following command: `git branch`

##### Issues and Milestones
First, commit frequently with decent messages related to your commited code.  
If your commit is closing an issue, add into your message `#close [id]`. Other keywords are available, chosse your prefering one: *close, closes, closed, fix, fixes, fixed, resolve, resolves, resolved*  
This project contains 3 milestones: **alpha, beta, gamma**. Alpha contains issues which should be closed before beta and gamma issues, and same for beta and gamma.
