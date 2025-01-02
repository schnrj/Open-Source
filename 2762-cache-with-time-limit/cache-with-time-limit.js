class TimeLimitedCache{
    constructor(){
        this.cache=new Map();
    }
    set(key,value,duration){
        const flag=this.cache.get(key);
        if(flag){
            clearTimeout(flag.timeout);
        }
        const timeout=setTimeout(()=>{
            this.cache.delete(key);
        },duration);
        this.cache.set(key,{value,timeout});
        return Boolean(flag);

    }
    get(key){
        if(this.cache.has(key)){
            return this.cache.get(key).value;
        }
        else return -1;
    }
    count(){
        return this.cache.size;
    }
}