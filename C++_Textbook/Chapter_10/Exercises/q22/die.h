class die
{
    public:
        void roll();
        int getNum() const { return num; }

        die();
    private:
        int num;
};