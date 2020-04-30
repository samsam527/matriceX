#ifndef MATRICX_H
#define MATRICX_H


class matricX
{
    public:
        matricX();
        matricX(int nbl, int nbc);
        matricX (const  matricX &A);
        void afficher();
        matricX &operator = (const matricX &A);
        double* operator [] (int i) const;
        matricX operator + (const matricX &A) const;
        matricX operator - (const matricX &A) const;
        matricX operator * (const matricX &A) const;
        matricX operator * (double a) const;
        matricX operator / (double a) const;
        matricX &operator += (const matricX &A);
        matricX &operator -= (const matricX &A);
        matricX &operator *= (const matricX &A);
        matricX &operator *= (double a);
        double**T;
        int nbl, nbc;
        virtual ~matricX();

    protected:

    private:
};

#endif // MATRICX_H
