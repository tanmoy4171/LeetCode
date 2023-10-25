class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t rst = 0;
		for (int i = 0; i < 32; ++i) {
			uint32_t t = n << i;
			t = t >> 31;
			t = t << i;
			rst += t;
		}
		return rst;
	}
};