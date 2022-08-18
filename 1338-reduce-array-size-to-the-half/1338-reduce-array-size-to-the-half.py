class Solution(object):
    def minSetSize(self, arr):
        l = [0]*100001
        for i in arr:
            l[i]+=1
        l.sort(reverse = True)
        n = len(arr)
        cnt = 0
        nos = 0
        for i in l:
            cnt = cnt + i
            nos = nos + 1
            if cnt >= (n/2):
                return nos
        return 0;
        