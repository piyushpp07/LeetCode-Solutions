class Solution {
private:
  double solve(double x, int n)
  { if(n == 0)
    return 1;
    if (n == 1)
      return x;
    double ans = solve(x, n/2);
    if (n % 2 == 0)
      return ans * ans;
    else return  x * ans * ans;
  }

public:
  double myPow(double x, int n) {

    if (n == 0)
      return 1;
    else {
 
      if (n > 0)
      {
        return solve(x, n);
      }
      else {

        return 1/solve(x, n);
      }

    }




  }
};