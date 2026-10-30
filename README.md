A memory scanner for linux, built in c.
(WIP)
## Setup

### Requirements
Clone the repository:
```bash
git clone https://github.com/SuperUserDo415/memoryScanner.git
```

Run:

```bash
gcc memscan.c -o memscan.out
```
```bash
sudo ./memscan.out [PID] [TARGET_VALUE]
```
After getting the address from memscan, we can run changemem
```bash
gcc changemem.c -o changemem.out
```
Then change the data stored to whatever:
```bash
sudo ./changemem.out [PID] [ADDRESS] [NEW_VALUE]
```
Now the value is changed.


## TODO:
1. Make search function
2. Be able to attach to programs directly from the tui
3. Better tui
4. Memory tables 
5. Be able to modify memory

