
namespace sct{

    /*
        set bit ->
        off bit->

        
    
    
    */

   /*
   Ej 5-> 0101, bit=0->
   */
    bool is_bit_active(int num, int bit){
        return (num & (1<<bit));
    }
}