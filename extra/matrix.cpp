#include<iostream>
#include<cstring> 
using namespace std;
const int MAXSIZE=100+1;
struct Matrix{
	
	int _arr[MAXSIZE][MAXSIZE];
	int row,col;
	
	Matrix(int i,int j){
		row=i,col=j;
		memset(_arr,0,sizeof _arr);
	}
	
	int getItem(int i,int j) const{
		return _arr[i][j];
	}
	void setItem(int i,int j,int val){
		_arr[i][j]=val;
	}
	
	Matrix operator* (const Matrix& o) const{
		if(col!=o.row){
			cout<<"Error in "<<__func__<<endl;
			exit(-1);
		}
		Matrix temp(row,o.col);
		for(int i=1;i<=row;++i)
			for(int j=1;j<=o.col;++j)
				for(int k=1;k<=col;++k)
					temp._arr[i][j]+=(this->getItem(i,k)*o.getItem(k,j));
		return temp;
	}
	void print() const{
		cout<<endl;
		for(int i=1;i<=row;++i){
			for(int j=1;j<=col;++j)cout<<getItem(i,j)<<" ";
			cout<<endl; 
		}
		cout<<endl;
	}
	void modify(){
		for(int i=1;i<=row;++i)
			for(int j=1;j<=col;++j)cin>>_arr[i][j];
	}
};

int main(){
	int row1,row2,col1,col2;
	
	cout<<"Please input the scale of Matrix1 "<<endl;
	cin>>row1>>col1;
	Matrix m1(row1,col1);
	cout<<"Please input the context of Matrix1 "<<endl;
	m1.modify();
	
	cout<<"Please input the scale of Matrix2 "<<endl;
	cin>>row2>>col2;
	Matrix m2(row2,col2);
	cout<<"Please input the context of Matrix2 "<<endl;
	m2.modify();
	
	Matrix m3=m1*m2;
	m3.print();
	return 0;
}
