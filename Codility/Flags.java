import java.util.ArrayList;
import java.lang.Math;

class Solution {
    public int solution(int[] A) {
        ArrayList<Integer> peaks = new ArrayList();
        
        for(int i=1; i<A.length-1; i++){
            if(A[i]>A[i-1] && A[i]>A[i+1]){
                peaks.add(i);
                i++;
            }
        }
        
        int count = peaks.size();
        
        if(count<2) return count;
        
        int maxFlags = (int)Math.round(Math.sqrt(peaks.get(count-1)-peaks.get(0))) + 1;
        maxFlags = maxFlags>count ? count:maxFlags;
        
        while(maxFlags>=2){
            int distance = maxFlags;
            int toFlag = maxFlags-1;
            int prior = 0;
            
            for(int i=1; i<count; i++){
                if(peaks.get(i)-peaks.get(prior) >= distance){//this peak is qualified to flag
                    toFlag--;
                    prior = i;
                } else { // not qualified to flag.
                    if(count-i-1<toFlag) {//not enough peaks remain to flag
                        maxFlags--;
                        break;
                    }
                }
            }
            if(toFlag==0) return maxFlags;
        }
        return maxFlags;
    }
}
