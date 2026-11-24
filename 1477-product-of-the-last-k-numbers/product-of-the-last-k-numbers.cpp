class ProductOfNumbers {
    vector<int>nums;
    vector<int>zeros;
public:
    ProductOfNumbers() {
        nums={};
        zeros={};
    }
    
    void add(int num) {

        if(nums.empty())
        {
        nums.push_back(num);
        zeros.push_back((num==0));
        }
        else
        {
            if(nums[nums.size()-1]!=0)
            num*=nums[nums.size()-1];
            nums.push_back(num);
            zeros.push_back((zeros[zeros.size()-1]+(num==0)));
        }
    }
    
    int getProduct(int k) {
        if(nums.size()==k && !(zeros[zeros.size()-1]-zeros[nums.size()-k]) && nums[0]!=0)
        return nums[nums.size()-1];
        else if (nums.size()==k || (zeros[zeros.size()-1]-zeros[nums.size()-k-1]))
        return 0;
        // k=(nums.size()-k)-1;
        // if(zeros[zeros.size()-1]-zeros[k])
        // return 0;
        // else if(nums[k]==0)
        // return nums[nums.size()-1];
        else if(nums[nums.size()-k-1]==0)
        return nums[nums.size()-1];
        else
        return nums[nums.size()-1]/nums[(nums.size()-k)-1];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */