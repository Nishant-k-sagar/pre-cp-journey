import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt()
    
    repeat(t) {
        val n = scanner.nextInt()
        
        var ans = 0
        
        for(i in 1..n){
          for(j in 1..n){
            if(i+j == n){
              ans++;
            }
          }
        }
        println(ans)
    }
}