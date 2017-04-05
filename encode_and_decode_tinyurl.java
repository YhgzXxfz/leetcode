public class Codec {
    HashMap<String,String> tinyUrlMap = new HashMap<>();
    HashMap<String,String> longUrlMap = new HashMap<>();
    String tinyPrefix = "https://tinyurl.com/";
    
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        if(longUrlMap.containsKey(longUrl)) return longUrlMap.get(longUrl);
        
        String tinyUrl = tinyPrefix+(longUrl.hashCode()+System.nanoTime());
        tinyUrlMap.put(tinyUrl,longUrl);
        longUrlMap.put(longUrl,tinyUrl);
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return tinyUrlMap.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
