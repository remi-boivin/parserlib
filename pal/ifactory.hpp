#ifndef IFACTORY_HPP
#define IFACTORY_HPP

#include <memory>
#include "./iparser.hpp"

namespace cp
{
    namespace iparser
    {
        class IFactory
        {
        public:
            virtual std::shared_ptr<IParser> createParser(std::vector<std::string> authorizedArgs) const = 0;

        protected:
            template <typename Abstract, typename Concrete, typename... Args>
            std::shared_ptr<Abstract> create(std::weak_ptr<Abstract> &weakRef, Args &&...args) const
            {
                if (weakRef.expired())
                {
                    auto shared = std::shared_ptr<Abstract>(std::make_shared<Concrete>(std::forward<Args>(args)...));
                    weakRef = shared;
                    return shared;
                }
                return weakRef.lock();
            }
        };
    }
}

#endif // IFACTORY_HPP