class Solution:
    def reverse(self, x: int) -> int:
        n=x<0
        x=abs(x)
        x=list(map(int,str(x)))
        x=x[::-1]
        y=int(''.join(map(str,x)))
        if y>2**31 -1:
            return 0
        return y if not n else -y