class matrix
{
    public:
    int rows,columns;
    double **data;

    matrix(int,int);
    matrix(const matrix& other);
    ~matrix();

    void fill(double value);
    matrix transpose()const;
    matrix operator+(const matrix &other) const;
    matrix operator*(const matrix &other) const;
    double sigmoid(double value);
    void applyfunction(double (*f)(double),double value);

    void display();
    
    private:
    void allocatememory();
    void deallocatememory();
};