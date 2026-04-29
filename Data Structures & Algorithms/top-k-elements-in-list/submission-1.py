class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq={}
        for num in nums:
            freq[num] = freq.get(num , 0)+1
        
        sorted_dic = dict(sorted(freq.items(), key=lambda x: x[1], reverse=True))
        ans = []
        for key in sorted_dic.keys():
            if k == 0:
                break
            
            ans.append(key)
            k -= 1
        
        return ans

        

        




