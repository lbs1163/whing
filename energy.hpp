#pragma once

#include <eosiolib/eosio.hpp>
#include <whing/level.hpp>
#include <whing/flap.hpp>
#include <eosio.token/eosio.token.hpp>
#include <eosiolib/asset.hpp>

namespace whing {
   class energy {
      public:
         void energy_down(account_name owner, uint64_t enr_amount);

         void energy_up(account_name owner, uint64_t wng_balance);

         inline int64_t get_max_enr(account_name owner) const;
         
         inline int64_t get_cur_enr(account_name owner) const;

      private:
         struct enr_account {
            account_name  owner;
            int64_t       max_enr; 
            int64_t       cur_enr;

            uint64_t primary_key()const { return owner; }
            EOSLIB_SERIALIZE( enr_account, (owner)(max_enr)(cur_enr) )
         };  

         typedef eosio::multi_index<N(enr_accounts), enr_account> enr_accounts;

   };

   energy::get_max_enr(account_name owner)const {
      enr_accounts enr_account_tbl(_self, owner);
      const auto &et = enr_account_tbl.get( owner );
      
      return et.max_enr;
   };

   energy::get_cur_enr(account_name owner)const {
      enr_accounts enr_account_tbl(_self, owner);
      const auto &et = enr_account_tbl.get( owner );
      
      return et.cur_enr;
   };

}

