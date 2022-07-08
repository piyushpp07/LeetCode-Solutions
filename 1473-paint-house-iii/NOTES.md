Question is good we just need to find the recurrence relation and the constrains box
Recurrence relation is :
fun(int idx,int prevc,int target)
if(house[i]!=0)
{
if(prevc == currcolor)
return fun(idx+1,prevc,target);
else return fun(idx+1,prevc,target-1);
}
// when there is no color and color need to be added
else{
//try all possibilities
for(int i = 0;i<color[0].size();i++)
{
if(i+1 ==prev)
ans = min(ans ,fun(idx+1,prevc,target));
else
ans = min(ans,fun(idx+1,i+1,target-1);
}
return ans ;
}