class Polynomial
{
    private :
        vector<int> data;

    public : 
        Polynomial()
        {
            data.resize(5);
        }

        void doubleCapacity()
        {
            vector<int> tmp;
            tmp.resize(2*data.size());

            for(int i = 0 ; i < data.size() ; ++i ){
                tmp[i] = data[i];
            }

            data = tmp;
        }
        void setCofficient(int degree , int coeff)
        {
            if(degree < 0){
                return ;
            }
            while(data.size() <= degree)
            {
                doubleCapacity();
            }

            data[degree] = coeff;
        }

        void print()
        {
            for(int i = 0 ; i<data.size() ; ++i){
                if(data[i] != 0){
                    cout << data[i] << "x" << " ";
                }
            }
        }

        Polynomial add(Polynomial arg){
            vector<int> tmp;
            tmp.resize(max(this->data.size() , arg.data.size()));
            int i = 0 ; j = 0 ; k = 0 ;
            while (i < this->data.size() && j < this->arg.data.size())
            {
                tmp[k++] = this->data[i++] + arg.data[j++];

            }

            while (i < this->data.size())
            {
                tmp[k++] = this->data[i++];
            }

            while (j < arg.data.size())
            {
                tmp[k++] = arg.data[j++];
            }

            Polynomial ret;
            ret.data = tmp;
            return ret;
            
        }
}