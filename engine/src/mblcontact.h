/* Copyright (C) 2003-2015 LiveCode Ltd.

This file is part of LiveCode.

LiveCode is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License v3 as published by the Free
Software Foundation.

LiveCode is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with LiveCode.  If not see <http://www.gnu.org/licenses/>.  */

#ifndef __MOBILE_CONTACT__
#define __MOBILE_CONTACT__

#include "mblsyntax.h"

typedef enum
{
	kMCContactPropertyUnknown,
	kMCContactPropertyTitle,				// iOS
	kMCContactPropertyMessage,				// iOS
	kMCContactPropertyAlternateName,		// iOS, Android (autogenerated in Android)
	kMCContactPropertyFirstName,			// iOS, Android
	kMCContactPropertyLastName,				// iOS, Android
	kMCContactPropertyMiddleName,			// iOS, Android
	kMCContactPropertyPrefix,				// iOS, Android
	kMCContactPropertySuffix,				// iOS, Android
	kMCContactPropertyNickName,				// iOS
	kMCContactPropertyFirstNamePhonetic,	// iOS, Android
	kMCContactPropertyLastNamePhonetic,		// iOS, Android
	kMCContactPropertyMiddleNamePhonetic,	// iOS, Android
	kMCContactPropertyOrganization,			// iOS, Android
	kMCContactPropertyJobTitle,				// iOS
	kMCContactPropertyDepartment,			// iOS
	kMCContactPropertyNote,					// iOS, Android
	
	kMCContactPropertyEmail,				// iOS, Android
	kMCContactPropertyPhone,				// iOS, Android
	kMCContactPropertyAddress,				// iOS, Android
} MCContactEntryProperty;

typedef enum
{
	kMCContactLabelHome,		// iOS, Android
	kMCContactLabelWork,		// iOS, Android
	kMCContactLabelOther,		// iOS, Android
	
	kMCContactLabelMobile,		// iOS
	kMCContactLabeliPhone,		// iOS
	kMCContactLabelMain,		// iOS
	kMCContactLabelHomeFax,		// iOS
	kMCContactLabelWorkFax,		// iOS
	kMCContactLabelOtherFax,	// iOS
	kMCContactLabelPager,		// iOS
} MCContactEntryLabel;

typedef enum
{
	kMCContactKeyStreet,		// iOS, Android
	kMCContactKeyCity,			// iOS, Android
	kMCContactKeyState,			// iOS, Android
	kMCContactKeyZip,			// iOS, Android
	kMCContactKeyCountry,		// iOS, Android
	kMCContactKeyCountryCode,	// iOS
} MCContactEntryKey;

bool MCContactAddProperty(MCArrayRef p_contact, MCNameRef p_property, MCStringRef p_value);
bool MCContactAddPropertyWithLabel(MCArrayRef p_contact, MCNameRef p_property, MCNameRef p_label, MCValueRef p_value);

bool MCSystemPickContact(int32_t& r_result);
bool MCSystemShowContact(int32_t p_contact_id, int32_t& r_result);
bool MCSystemCreateContact(int32_t& r_result);
bool MCSystemUpdateContact(MCArrayRef p_contact, MCStringRef p_title, MCStringRef p_message, MCStringRef p_alternate_name, int32_t &r_result);
bool MCSystemGetContactData(int32_t p_contact_id, MCArrayRef& r_contact_data);
bool MCSystemRemoveContact(int32_t p_contact_id);
bool MCSystemAddContact(MCArrayRef p_contact, int32_t &r_result);
bool MCSystemFindContact(MCStringRef p_contact_name, MCStringRef& r_result);

#endif
