ofstream outfile1("myfile1.txt");
ofstream outfile2;
outfile2.open("myfile2.txt");
outfile1<< xxx
outfile1.close();
outfile1.open(".txt", ios::app);

ifstream infile1(".txt");
infile1>> xxx;
infile1.close();

char ch;
fin.get(ch);
while(!fin.eof()){ //从头读到文件结束
    fout.put(ch);
    fin.get(ch);
}

ofstream fout(".txt", ios::binary);
int Len = strlen(str);
fout.write((char*)(&Len), sizeof(int));
fout.write(str, len);

fin.seekg(i*sizeof(int));  
fin.read((char*)(&x), sizeof(int));  
cout<<x<<" ";


string res,temp;
stringstream ss(s);
while(ss>>temp)