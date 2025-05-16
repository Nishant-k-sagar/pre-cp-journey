import java.util.*


fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt()
    
    repeat(t) {
        var n = readLine()!!.toInt()
        val s = readLine()!!

        val mp = mutableMapOf<Char, INT>()

        for(i in 0 until n){
            mp[s[i]] = mp.getOrDefault(s[i], 0) + 1
        }

        if(n==1){
            println("YES")
            continue
        }

        var flag = false
        for((_, it) in mp){
            if(it>=2){
                flag = true
                break
            }
        }

        if(flag){
            println("YES")
        }
        else{
            println("NO")
        }
    }
}
