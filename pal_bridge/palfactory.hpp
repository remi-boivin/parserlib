#ifndef PARSER_PALFACTORY
#define PARSER_PALFACTORY

#include <memory>
#include "../../pal/ifactory.hpp"

namespace cp
{
    namespace parser
    {
        class PALFactory : public iparser::IFactory
        {
        public:
            std::shared_ptr<iparser::IParser> createParser(std::vector<std::string> authorizedArgs) const override;

        private:
            mutable std::weak_ptr<iparser::IParser> m_parserRef;
        };

    }
}

#endif // PARSER_PALFACTORY
