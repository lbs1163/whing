#include <whing/energy.hpp>

namespace whing {
   void energy::energy_down(account_name owner, uint64_t enr_amount) {
      require_auth( _self );
      eosio_assert(enr_amount <= get_max_enr(owner), "not enough energy to down");

      asset transfer_wng = asset(enr_amount, symbol_type("WNG"));
      eosio.token::transfer(wng_owner, owner, transfer_wng);
      
      enr_accounts& enr_table;
      auto existing = enr_table.find( owner );
      enr_table.modify( existing, 0, [&]( auto& obj ) { 
         obj.max_enr -= wng_balance;
      }); 
   }

   void energy::energy_up(account_name owner, uint64_t wng_balance) {
      require_auth( _self );
      eosio_assert(wng_balance >= whing.token::get_balance() . "not enough whing to up");
      
      asset transfer_wng = asset(wng_balance, symbol_type("WNG"));
      eosio.token::transfer(owner, wng_owner, transfer_wng);

      enr_accounts& enr_table;
      auto existing = enr_table.find( owner );
      enr_table.modify( existing, 0, [&]( auto& obj ) { 
         obj.max_enr += wng_balance;
      }); 
   } 

}
