1. Install [python3](https://www.python.org/downloads/)
	- Add to PATH
1. Download [interactive_runner script](https://storage.googleapis.com/coding-competitions.appspot.com/interactive_runner.py) (https://codingcompetitions.withgoogle.com/codejam/faq#interactive-problems)
1. Download `local_testing_tool.py` from link in the task description
1. Modify `local_testing_tool.py` for better debugging
1. Write debug messages to file
```c++
#ifdef _WIN32
#define dbg if(true) f <<
#else
#define dbg if(false) f <<
#endif // _WIN32

using namespace std;

ofstream f("out.txt");

int main(){
	//...
	f.Close();
}
```
1. Use command line mentioned in `interactive_runner.py`