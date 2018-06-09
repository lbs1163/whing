#pragma once
#include <level.hpp>

namespace whing {

  struct board {

    uint32_t       board_id; // pseudo-random
    std::string    url;
    uint64_t       exp;
    uint32_t       level; // user's level, exp/EXP_THRESHOLD
    account_name   owner;

    uint64_t       num_of_articles;

    board(uint32_t _id, std::string _url, account_name _owner)
          : board_id(_id), url(_url), exp(0), level(0), owner(_owner), num_of_articles(0) {}

    std::vector<article_id> article_list;

    uint64_t primary_key() const { return board_id; }
    uint64_t secondary_key() const { return owner; }

  };

  struct article {

    uint32_t       article_id; // pseudo-random
    std::string    url;
    uint64_t       exp;
    account_name   owner;

    uint64_t       created_time;
    std::string    title;
    std::string    data;
    std::string    img_url;

    uint64_t       num_of_flaps;
    uint64_t       num_of_replies;

    article(uint32_t _id, std::string _url, account_name owner,
            std::string _title, std::string _data, std::string _img_url,
            uint64_t created_time)
          : article_id(_id), url(_url), exp(0), level(0), owner(_owner),
            title(_title), data(_data), img_url(_img_url),
            num_of_flaps(0), num_of_replies(0) {}

    uint64_t primary_key() const { return article_id; }
    uint64_t secondary_key() const { return owner; }

    // 	serialized(reply_id…)
  };

  struct reply {

    uint64_t       reply_id; // pseudo-random
    uint64_t       article_id;
    std::string    article_author;
    std::string    url;
    account_name   owner;

    uint64_t       exp;
    uint64_t       created_time;

    std::string    data;

    uint64_t       num_of_flaps;

    reply(uint32_t _id, uint32_t _id2, std::string _article_author, std::string _url,
          uint64_t created_time, account_name owner, std::string _data)
          : reply_id(_id), replied_article_id(_id2), article_author(_article_author), url(_url),
            owner(_owner), exp(0), created_time(_created_time), data(_data), num_of_flaps(0) {}

    uint64_t primary_key() const { return reply_id; }
    uint64_t secondary_key() const { return owner; }

    //	serialized (reply_id…)

  };

} // end of namespace whing
