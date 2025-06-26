#include<bits/stdc++.h>
using namespace std;
const char *way[4] = {"ASCII", "UNICODE", "UTF8", "ANSI"};

string s;
int l, flag;
char op;

class File{
protected:
    string filesize;
    int len;
public:
    virtual void UpdateFile()=0;
    virtual void show()=0;
};

class Cname : public File{
public:
    int f;
    Cname(string& s, int l, int flag) : f(flag){
        filesize = s;
        len = l;
    }
    void UpdateFile() {
		cin >> s >> flag;
		filesize = s;
		f = flag;
    }
    void show() {
        cout << filesize << ' ' << len << ' ' << way[f] << endl;
    }
};

class Csize : public File{
public:
    int f;
    Csize(string& s, int l, int flag) : f(flag) { // 添加构造函数
        filesize = s;
        len = l;
    }
    void UpdateFile(){
		cin >> l >> flag;
		len = l;
		f = flag;
    }
    void show() {
        cout << filesize << ' ' << len << ' ' << way[f] << endl;
    }
};

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s >> l >> flag;
	cin >> op;
	File *p;
	if (op == 'N') {
		string newName;
		int newFlag;
		p = new Cname(s, l, flag);
		p->UpdateFile();
		p->show();
	} 
	else if (op == 'S') {
		int newSize, newFlag;
		p = new Csize(s, l, flag);
		p->UpdateFile();
		p->show();
	}
	return 0;
}
