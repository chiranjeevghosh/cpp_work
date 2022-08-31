#include<iostream>
#include<vector>

using namespace std;

class Matrix {
    private:
        vector<vector<int>> VEC;

    public:
        Matrix () {}
        Matrix (const vector<vector<int>>& v) {
            VEC = v;
        }
        Matrix operator*(const Matrix& m1) {
            int M = VEC.size();
            int N = VEC[0].size();
            if (N != m1.VEC.size()) {
                cout << "ERROR: Can't multiply these matrices" << endl;
                Matrix m({{0},{0}});
                return m;
            }
            int K = m1.VEC[0].size();
            vector<int> vk(K,0);
            vector<vector<int>> v;
            for (int i=0; i<M; i++) {
                v.push_back(vk);
            }
            Matrix m(v);
            for (int i=0; i<M; i++) {
                for (int k=0; k<K; k++) {
                    for (int j=0; j<N; j++) {
                        m.VEC[i][k]+=VEC[i][j]*m1.VEC[j][k];
                    }
                }
            }
            return m;
            
        }
        Matrix operator~() {
            int M = VEC.size();
            int N = VEC[0].size();
            vector<int> vm(M,0);
            vector<vector<int>> v;
            for (int i=0; i<N; i++) {
                v.push_back(vm);
            }
            for (int i=0; i<N; i++) {
                for (int j=0; j<M; j++) {
                    v[i][j] = VEC[j][i];
                }
            }
            Matrix m(v);
            return m;
        }
        void showMatrix(){
            for (int i=0; i<VEC.size(); i++) {
                for (int j=0; j<VEC[i].size(); j++) {
                    cout << VEC[i][j] << ", ";
                }
                cout << endl;
            }
        }
        
};

int main() {
    vector<vector<int>> v1 = {{1,2,3},
                              {1,1,4}};
    vector<vector<int>> v2 = {{0,1,4,2,0},
                              {3,1,0,1,2},
                              {0,2,0,2,3}};
    Matrix m1(v1);
    Matrix m2(v2);
    Matrix m3 = m1*m2;
    m3.showMatrix();
    Matrix m4 = ~m3;
    m4.showMatrix();
    Matrix m5 = m4;
    //m5 = m4;
    m5.showMatrix();
    return 0;
}