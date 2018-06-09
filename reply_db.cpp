#include <whing/reply_db.cpp>

namespace whing {

   reply reply_db::get_reply_by_id(uint32_t id) {
      replies replies_tbl(_self, id);
      const auto &at = replies_tbl.get( id );

      return at;
   };

   owned_infos reply_db::get_owned_infos(account_name owner) {
      auto reply_index = replies.get_index<N(by_owner)>();
      auto itr = reply_index.lower_bound(owner);

      owned_infos oi;

      for( const auto& itr : replies.get_index<N(by_owner)>() ) {
         if (itr.owner == owner) { 
            oi.total_flaps += itr.num_flaps;
            oi.counts += 1;
         }
      }

      return oi;
   };

};
