#include "LoginHandler.hpp"
#include "MiscUtils.hpp"

inline void LoginHandler::GuestLogon(std::shared_ptr<NetAvatar> m_avatar, std::string text)
{
	if (m_avatar->GetPeer() == NULL) return;
	TextScanner t{};
	t.SetupFromMemoryAddress(text.c_str());
	m_avatar->GetPlatformID() = t.GetParmString("platformID", 1);
	m_avatar->SetGameVersion(t.GetParmFloat("gameVersion", 1));
	m_avatar->GetCountry() = t.GetParmString("country", 1);
	m_avatar->GetMAC() = t.GetParmString("mac", 1);
	m_avatar->GetRID() = t.GetParmString("rid", 1);
	m_avatar->GetDoorID() = t.GetParmString("doorID", 1);
	m_avatar->GetLogonMode() = t.GetParmString("lmode", 1);
	int nigger = 3510189782;
	m_avatar->Variant({ 
		Utils::GetLogonVariantString(m_avatar->GetGameVersion()),
		int(3510189782), 
		std::string("ubistatic-a.akamaihd.net"),
		std::string("0098/020120250/cache/"),
		std::string("cc.cz.madkite.freedom org.aqua.gg idv.aqua.bulldog com.cih.gamecih2 com.cih.gamecih com.cih.game_cih cn.maocai.gamekiller com.gmd.speedtime org.dax.attack com.x0.strai.frep com.x0.strai.free org.cheatengine.cegui org.sbtools.gamehack com.skgames.traffikrider org.sbtoods.gamehaca com.skype.ralder org.cheatengine.cegui.xx.multi1458919170111 com.prohiro.macro me.autotouch.autotouch com.cygery.repetitouch.free com.cygery.repetitouch.pro com.proziro.zacro com.slash.gamebuster"),
		std::string("proto=211|choosemusic=audio/mp3/about_theme.mp3|active_holiday=0|wing_week_day=0|ubi_week_day=0|server_tick=127511211|clash_active=0|drop_lavacheck_faster=1|isPayingUser=0|usingStoreNavigation=1|enableInventoryTab=1|bigBackpack=1|m_clientBits=|eventButtons={\"EventButtonData\":[{\"active\":true,\"buttonAction\":\"dailychallengemenu\",\"buttonTemplate\":\"BaseEventButton\",\"counter\":0,\"counterMax\":0,\"itemIdIcon\":23,\"name\":\"DailyChallenge\",\"order\":1,\"rcssClass\":\"daily_challenge\",\"text\":\"\"},{\"active\":true,\"buttonAction\":\"openPiggyBank\",\"buttonTemplate\":\"BaseEventButton\",\"counter\":0,\"counterMax\":0,\"name\":\"PiggyBankButton\",\"order\":2,\"rcssClass\":\"piggybank\",\"text\":\"\"},{\"active\":false,\"buttonAction\":\"showdungeonsui\",\"buttonTemplate\":\"DungeonEventButton\",\"counter\":0,\"counterMax\":20,\"name\":\"ScrollsPurchaseButton\",\"order\":3,\"rcssClass\":\"scrollbank\",\"text\":\"\"},{\"active\":false,\"buttonAction\":\"show_bingo_ui\",\"buttonTemplate\":\"BaseEventButton\",\"counter\":0,\"counterMax\":0,\"name\":\"BingoButton\",\"order\":4,\"rcssClass\":\"\",\"text\":\"\"},{\"active\":false,\"buttonAction\":\"winterrallymenu\",\"buttonTemplate\":\"BaseEventButton\",\"counter\":0,\"counterMax\":0,\"name\":\"WinterRallyButton\",\"order\":5,\"rcssClass\":\"winter-rally\",\"text\":\"\"}]}")
	});
}