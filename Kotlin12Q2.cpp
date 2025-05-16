import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt()
    
    repeat(t) {
        val n = scanner.nextInt()
        val s = scanner.next()
        
        var dash = 0
        var underscore = 0
        
        for (ch in s) {
            if (ch == '-') dash++
            else if (ch == '_') underscore++
        }
        
        if (dash < 2 || underscore < 1) {
            println("0")
        } else {
            
            val a = dash / 2
            val b = dash - a
            
            val res = a.toLong() * underscore.toLong() * b.toLong()
            
            println(res)
        }
    }
}