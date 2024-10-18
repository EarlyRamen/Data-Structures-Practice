#include <string>

#ifndef E7B9ECA5_F466_4CCE_A2CA_E60D7F4C470E
#define E7B9ECA5_F466_4CCE_A2CA_E60D7F4C470E

const static std::string alphabet{"ATCG"};

std::string randomString(const std::string&, size_t);

std::string lcs(const std::string&, const std::string&);

static std::string lcs(const std::string&, const std::string&, int, int);

#endif /* E7B9ECA5_F466_4CCE_A2CA_E60D7F4C470E */
