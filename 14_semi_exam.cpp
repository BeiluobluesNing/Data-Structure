/*
给定一个正整数序列 S 和一个整数 p，请设计一个算法判断是否存在一个连续子序列 S’，
使得 S’的所有元素之和恰好为 p。尽量优化你的算法并分析其时间复杂度。
仅需遍历一次数组，头节点j也仅需向数组尾进行单次便利，最多n次操作。
则O(n)
 */
bool seqsum(int *s,int n, int p){
	int b = new int[n];
	int j = 0;
	b[0] = s[0];
	for(int i=1;i<n;i++){
		if(b[i-1]+s[i]<p)
		{
			b[i] = b[i] + s[i];
		}
		else if(b[i-1]+s[i] == p)
			return true;
		else{
			while(k<i && b[i-1]-s[k]>p)
			{
				b[i-1] = b[i-1]-s[k];
				k++;
			}
		}
	}
	return false;
}


