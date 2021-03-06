#include <whing/article.hpp>

namespace whing {
   article get_article_by_id(uint32_t id) {
      articles articles_tbl(_self, id);
      const auto &at = articles_tbl.get( id );

      return at;
   };

   owned_articles get_owned_articles(account_name owner) {
      owned_articles oi;

      for( const auto& itr : articles.get_index<N(by_owner)>() ) {
         if (itr.owner == owner) { 
            oi.total_flaps += itr.num_flaps;
            oi.counts += 1;
            oi.total_replies += num_replies; 
         }
      }

      return oi;
   };

   vector<article> get_articles_by_board_id(uint32_t board_id) {
      vector<article> vec_article;
      
      for( const auto& itr : articles.get_index<N(by_board_id)>() ) {
         if(itr.board_id == board_id) {
            vec_articles.push_back(itr);
         }
      }
   
      return vec_article;
   };
};
