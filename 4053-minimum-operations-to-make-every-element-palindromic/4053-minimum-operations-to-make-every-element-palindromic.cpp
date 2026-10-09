class Solution {
public:
    
    long long buildPalin(long long half, int totalLen) {
        long long tmp = (totalLen & 1) ? (half / 10) : half;
        long long rev = 0;
        while (tmp > 0) {
            rev = rev * 10 + tmp % 10;
            tmp /= 10;
        }
        long long mult = 1;
        int shift = totalLen >> 1;
        for (int i = 0; i < shift; i++) mult *= 10;
        return half * mult + rev;
    }
    
    long long largestPalinWithParity(int L, int parity) {
        if (L == 1) return (parity == 0) ? 8 : 9;
        if (parity == 1) {
            long long val = 0;
            for (int i = 0; i < L; i++) val = val * 10 + 9;
            return val;
        } else {
            long long val = 8;
            for (int i = 0; i < L - 2; i++) val = val * 10 + 9;
            val = val * 10 + 8;
            return val;
        }
    }
    
    long long smallestPalinWithParity(int L, int parity) {
        if (L == 1) return (parity == 0) ? 2 : 1;
        long long first = (parity == 0) ? 2 : 1;
        long long val = first;
        for (int i = 0; i < L - 2; i++) val = val * 10;
        val = val * 10 + first;
        return val;
    }
    
    long long minOpsForElement(long long x) {
        string xStr = to_string(x);
        int len = xStr.size();
        int halfLen = (len + 1) / 2;
        long long halfVal = stoll(xStr.substr(0, halfLen));
        int parity = x % 2;
        
        long long candidates[32];
        int cnt = 0;
        
        // Nearby half values
        for (long long d = -3; d <= 3; d++) {
            long long h = halfVal + d;
            if (h <= 0) continue;
            long long t = h;
            int digits = 0;
            while (t > 0) { digits++; t /= 10; }
            if (digits != halfLen) continue;
            candidates[cnt++] = buildPalin(h, len);
        }
        
        // Handle first-digit parity
        if (halfLen >= 1) {
            long long tenPowHalf = 1;
            for (int i = 1; i < halfLen; i++) tenPowHalf *= 10;
            
            long long firstDigit = halfVal / tenPowHalf;
            
            if (firstDigit % 2 != parity) {
                long long lowerFD = firstDigit - 1;
                if (lowerFD % 2 != parity) lowerFD--;
                if (lowerFD >= 1) {
                    long long lowerHalf = lowerFD * tenPowHalf + (tenPowHalf - 1);
                    candidates[cnt++] = buildPalin(lowerHalf, len);
                }
                
                long long upperFD = firstDigit + 1;
                if (upperFD % 2 != parity) upperFD++;
                if (upperFD <= 9) {
                    long long upperHalf = upperFD * tenPowHalf;
                    candidates[cnt++] = buildPalin(upperHalf, len);
                }
            }
        }
        
        // Single digit palindromes
        for (long long p = 1; p <= 9; p++) candidates[cnt++] = p;
        
        // Fewer digits
        if (len > 1) candidates[cnt++] = largestPalinWithParity(len - 1, parity);
        
        // More digits
        candidates[cnt++] = smallestPalinWithParity(len + 1, parity);
        
        long long best = LLONG_MAX;
        for (int i = 0; i < cnt; i++) {
            long long p = candidates[i];
            if (p <= 0 || (p & 1) != parity) continue;
            long long diff = x - p;
            if (diff < 0) diff = -diff;
            long long ops = diff >> 1;
            if (ops < best) best = ops;
        }
        
        return best;
    }
    
    long long minOperations(vector<int>& nums) {
        
        vector<int> virelqunox = nums;
        
        long long ans = 0;
        
        for (int i = 0; i < (int)virelqunox.size(); i++) {
            ans += minOpsForElement(virelqunox[i]);
        }
        
        return ans;
    }
};