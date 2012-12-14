/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : BondSM_sm.sm
 */

#include "bondcpp/bond.h"
#include "bondcpp/BondSM_sm.h"

using namespace statemap;

// Static class declarations.
SM_WaitingForSister SM::WaitingForSister("SM::WaitingForSister", 0);
SM_Alive SM::Alive("SM::Alive", 1);
SM_AwaitSisterDeath SM::AwaitSisterDeath("SM::AwaitSisterDeath", 2);
SM_Dead SM::Dead("SM::Dead", 3);

void BondSMState::ConnectTimeout(BondSMContext& context)
{
    Default(context);
    return;
}

void BondSMState::Die(BondSMContext& context)
{
    Default(context);
    return;
}

void BondSMState::DisconnectTimeout(BondSMContext& context)
{
    Default(context);
    return;
}

void BondSMState::HeartbeatTimeout(BondSMContext& context)
{
    Default(context);
    return;
}

void BondSMState::SisterAlive(BondSMContext& context)
{
    Default(context);
    return;
}

void BondSMState::SisterDead(BondSMContext& context)
{
    Default(context);
    return;
}

void BondSMState::Default(BondSMContext& context)
{
    throw (
        TransitionUndefinedException(
            context.getState().getName(),
            context.getTransition()));

    return;
}

void SM_WaitingForSister::ConnectTimeout(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.Death();
        context.setState(SM::Dead);
    }
    catch (...)
    {
        context.setState(SM::Dead);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_WaitingForSister::Die(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.Death();
        context.setState(SM::Dead);
    }
    catch (...)
    {
        context.setState(SM::Dead);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_WaitingForSister::SisterAlive(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.Connected();
        context.setState(SM::Alive);
    }
    catch (...)
    {
        context.setState(SM::Alive);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_WaitingForSister::SisterDead(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.Connected();
        ctxt.SisterDied();
        ctxt.Death();
        context.setState(SM::Dead);
    }
    catch (...)
    {
        context.setState(SM::Dead);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_Alive::Die(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.StartDying();
        context.setState(SM::AwaitSisterDeath);
    }
    catch (...)
    {
        context.setState(SM::AwaitSisterDeath);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_Alive::HeartbeatTimeout(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.Death();
        context.setState(SM::Dead);
    }
    catch (...)
    {
        context.setState(SM::Dead);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_Alive::SisterAlive(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.Heartbeat();
        context.setState(SM::Alive);
    }
    catch (...)
    {
        context.setState(SM::Alive);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_Alive::SisterDead(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.SisterDied();
        ctxt.Death();
        context.setState(SM::Dead);
    }
    catch (...)
    {
        context.setState(SM::Dead);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_AwaitSisterDeath::Die(BondSMContext& context)
{

    (context.getState()).Exit(context);
    context.setState(SM::AwaitSisterDeath);
    (context.getState()).Entry(context);

    return;
}

void SM_AwaitSisterDeath::DisconnectTimeout(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.Death();
        context.setState(SM::Dead);
    }
    catch (...)
    {
        context.setState(SM::Dead);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_AwaitSisterDeath::HeartbeatTimeout(BondSMContext& context)
{

    (context.getState()).Exit(context);
    context.setState(SM::AwaitSisterDeath);
    (context.getState()).Entry(context);

    return;
}

void SM_AwaitSisterDeath::SisterAlive(BondSMContext& context)
{

    (context.getState()).Exit(context);
    context.setState(SM::AwaitSisterDeath);
    (context.getState()).Entry(context);

    return;
}

void SM_AwaitSisterDeath::SisterDead(BondSMContext& context)
{
    BondSM& ctxt(context.getOwner());

    (context.getState()).Exit(context);
    context.clearState();
    try
    {
        ctxt.Death();
        context.setState(SM::Dead);
    }
    catch (...)
    {
        context.setState(SM::Dead);
        throw;
    }
    (context.getState()).Entry(context);

    return;
}

void SM_Dead::ConnectTimeout(BondSMContext& context)
{

    (context.getState()).Exit(context);
    context.setState(SM::Dead);
    (context.getState()).Entry(context);

    return;
}

void SM_Dead::Die(BondSMContext& context)
{

    (context.getState()).Exit(context);
    context.setState(SM::Dead);
    (context.getState()).Entry(context);

    return;
}

void SM_Dead::DisconnectTimeout(BondSMContext& context)
{

    (context.getState()).Exit(context);
    context.setState(SM::Dead);
    (context.getState()).Entry(context);

    return;
}

void SM_Dead::HeartbeatTimeout(BondSMContext& context)
{

    (context.getState()).Exit(context);
    context.setState(SM::Dead);
    (context.getState()).Entry(context);

    return;
}

void SM_Dead::SisterAlive(BondSMContext& context)
{

    (context.getState()).Exit(context);
    context.setState(SM::Dead);
    (context.getState()).Entry(context);

    return;
}

void SM_Dead::SisterDead(BondSMContext& context)
{

    (context.getState()).Exit(context);
    context.setState(SM::Dead);
    (context.getState()).Entry(context);

    return;
}

/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */
