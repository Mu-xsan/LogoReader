#include <iostream>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <algorithm>
# include <vector>
#ifdef linux  
#include <unistd.h>  
#include <dirent.h>  
#endif  

using namespace std;


/** 
 * @function: 获取cate_dir目录下的所有文件名 
 * @param: cate_dir - string类型 
 * @result：vector<string>类型 
*/  


vector<string> getFiles(string cate_dir)  
{  
    vector<string> files;//存放文件名  
#ifdef linux  
    DIR *dir;  
    struct dirent *ptr;  
    char base[1000];  
   	string p;
    if ((dir=opendir(cate_dir.c_str())) == NULL)  
        {  
        perror("Open dir error...");  
                exit(1);  
        }  
   
    while ((ptr=readdir(dir)) != NULL)  
    {  
        if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir  
                continue;  
        else if(ptr->d_type == 8)    ///file  
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);  
            files.push_back(ptr->d_name);
			//cout << ptr->d_name << endl;  
			
        else if(ptr->d_type == 10)    ///link file  
            //printf("d_name:%s/%s\n",basePath,ptr->d_name);  
            continue;  
        else if(ptr->d_type == 4)    ///dir  
        {  
			//files.push_back(p.assign(cate_dir).append("/").append(ptr->d_name)); 
            files.push_back(ptr->d_name);  
            /* 
                memset(base,'\0',sizeof(base)); 
                strcpy(base,basePath); 
                strcat(base,"/"); 
                strcat(base,ptr->d_nSame); 
                readFileList(base); 
            */  
        }  
    }  
    closedir(dir);  
#endif  
  
    //排序，按从小到大排序  
	sort(files.begin(), files.end());
    return files;  
}


vector<vector<string> > getAllFiles(string cate_dir) {
    vector<string> subdir = getFiles(cate_dir);
	cout << subdir.size() <<endl;
    vector<vector<string> > total(51, vector<string>());
    string p;
	vector<string> temp;
    for (int i = 0; i < 51; ++i) {
        temp = getFiles(p.assign(cate_dir).append("/").append(subdir[i]));
		for (int j = 0; j < temp.size(); ++j) {
			temp[j] = p.assign(cate_dir).append("/").append(subdir[i]).append("/").append(temp[j]);
		}
		total[i] = temp;
		cout << i << " " << p.assign(cate_dir).append("/").append(subdir[i]) << endl;
    }
    return total;
}

int main(void)  
{  
    DIR *dir;  
    string basePath = "/root/Desktop/LogoReader/data/CarLogos51";
  	cout << basePath << endl;
       
    cout<<endl<<endl;  
    vector<vector<string> > files=getAllFiles(basePath);
    for (int i=0; i<files.size(); i++)  
    {  
		// cout << i << endl;
		for (int j = 0; j < files[i].size(); ++j) {
			cout << files[i][j] << " ";  
		}
		    cout << endl;
    }  
  
  
    
    return 0;  
}  
