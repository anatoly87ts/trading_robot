#include "market_base_t.h"
#include "strategy_base_t.h"
#include "symbol_base_t.h"

namespace trading
{

//-------------------------------------------------------------------
//-------------------------------------------------------------------

market_base_t::market_base_t()
{
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------

market_base_t::~market_base_t()
{

}

//-------------------------------------------------------------------
//-------------------------------------------------------------------

void market_base_t::add_strategy(strategy_base_t* strategy)
{
    m_strategies.push_back(strategy);
    init_strategy(strategy);
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------

void market_base_t::process_strategies()
{
    for (auto& strategy : m_strategies)
    {
        if (strategy->symbol().is_ready())
            strategy->process();
    }
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------

}