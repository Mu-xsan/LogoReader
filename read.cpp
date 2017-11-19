# include <iostream>
# include <io.h>
# include <string>
# include <vector>
using namespace std;
int order = 0;
void getFiles(string path, vector<vector<string> >& infor) {
    long hFile = 0;
    struct _finddata_t fileinfor;
    string p;
    hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfor);
    if (hFile != -1) {
        do {
            if (fileinfor.attrib & _A_SUBDIR) {
                string curFile = fileinfor.name;
                cout << p.assign(path).append("/").append(curFile) << endl;
                
                getFiles(p.assign(path).append("/").append(curFile), infor);
                infor.push_back(vector<string>());

                
                
                
            } else {
                infor[order].push_back(p.assign(path).append("/").append(fileinfor.name));
                
            }
        } while(_findnext(hFile, &fileinfor) == 0);
        ++order;
        // cout << order << endl;
        _findclose(hFile);
    }
}

int main() {
    string path = "/root/Desktop/LogoReader/data/CarLogos51";
    cout << path << endl;
    vector<vector<string> > all;
    getFiles(path, all);
    for (int i = 0; i < all.size(); ++i) {
        for (int j = 0; j < all[i].size(); ++j) {
            cout << all[i][j] << " ";
        }
        cout << endl;
    }
}
