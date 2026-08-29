This file contains a list of the packets and their types used by Twisted Metal: Harbor City.

Packets are listed in the same registration order as in RegisterPackets @ 0x227380.

Public keys (as found in `KM_GetMediusPublicKey`):
- `BD6DE09814860155` - public server key
- `5434D1D124B30B11`
- `3EABB87FAE576E73`
- `008054A0EF459E7E`
- `852E264E569D2802`
- `FC3211DB9C164F41`
- `25689F91FF85ED9B`
- `C4F75716EC835D23`

TODO: Write descriptions of packet + packet format (like wiki.vg)

| Packet ID | Packet Type | Address     | Callback                                                             | Description |
|-----------|-------------|-------------|----------------------------------------------------------------------|-------------|
| 0x4       | 1           | `0x232c6a8` | `MediusUniqueCallbackSessionBeginResponseHandler`                    |             |
| 0x6       | 1           | `0x232c708` | `MediusUniqueCallbackSessionEndResponseHandler`                      |             |
| 0x8       | 1           | `0x232c758` | `MediusUniqueCallbackAccountLoginResponseHandler`                    |             |
| 0x10      | 1           | `0x232c7e8` | `MediusUniqueCallbackAccountRegistrationResponseHandler`             |             |
| 0xc       | 1           | `0x232c820` | `MediusUniqueCallbackAccountGetProfileResponseHandler`               |             |
| 0xe       | 1           | `0x232c858` | `MediusUniqueCallbackAccountUpdateProfileResponseHandler`            |             |
| 0x10      | 1           | `0x232c890` | `MediusUniqueCallbackAccountUpdatePasswordResponseHandler`           |             |
| 0x12      | 1           | `0x232c8c8` | `MediusUniqueCallbackAccountUpdateStatsResponseHandler`              |             |
| 0x14      | 1           | `0x232d678` | `MediusUniqueCallbackAccountDeleteResponseHandler`                   |             |
| 0x16      | 1           | `0x232c7b0` | `MediusUniqueCallbackAccountLogoutResponseHandler`                   |             |
| 0x18      | 1           | `0x232d6b0` | `MediusUniqueCallbackAccountGetIDResponseHandler`                    |             |
| 0x1a      | 1           | `0x232c900` | `MediusUniqueCallbackAnonymousLoginResponseHandler`                  |             |
| 0x1c      | 1           | `0x232d598` | `MediusUniqueCallbackGetMyIPResponseHandler`                         |             |
| 0x1e      | 1           | `0x232c938` | `MediusUniqueCallbackCreateGameResponseHandler`                      |             |
| 0x22      | 1           | `0x232c970` | `MediusUniqueCallbackCreateChannelResponseHandler`                   |             |
| 0x24      | 1           | `0x232c9a8` | `MediusUniqueCallbackJoinGameResponseHandler`                        |             |
| 0x26      | 1           | `0x232c9e0` | `MediusUniqueCallbackJoinChannelResponseHandler`                     |             |
| 0x28      | 1           | `0x232ca18` | `MediusUniqueCallbackJoinChannelFwdResponseHandler`                  |             |
| 0x2a      | 1           | `0x232ca20` | `MediusUniqueCallbackGameListResponseHandler`                        |             |
| 0x2c      | 1           | `0x232ca58` | `MediusUniqueCallbackChannelListResponseHandler`                     |             |
| 0x2e      | 1           | `0x232ca90` | `MediusUniqueCallbackLobbyWorldPlayerListResponseHandler`            |             |
| 0x30      | 1           | `0x232cac8` | `MediusUniqueCallbackGameWorldPlayerListResponseHandler`             |             |
| 0x32      | 1           | `0x232cb00` | `MediusUniqueCallbackPlayerInfoResponseHandler`                      |             |
| 0x36      | 4           | `0x232cb38` | `MediusUniqueCallbackGameInfoResponseHandler`                        |             |
| 0x36      | 1           | `0x232cb70` | `MediusUniqueCallbackChannelInfoResponseHandler`                     |             |
| 0x38      | 1           | `0x232cba8` | `MediusUniqueCallbackFindWorldByNameResponseHandler`                 |             |
| 0x3a      | 1           | `0x232cbe0` | `MediusUniqueCallbackFindPlayerResponseHandler`                      |             |
| 0x3e      | 1           | `0x232cc98` | `MediusUniqueCallbackGetBuddyListResponseHandler`                    |             |
| 0x40      | 1           | `0x232ccd0` | `MediusUniqueCallbackAddToBuddyListResponseHandler`                  |             |
| 0x42      | 1           | `0x232cd08` | `MediusUniqueCallbackRemoveFromBuddyListResponseHandler`             |             |
| 0x44      | 1           | `0x232cd40` | `MediusUniqueCallbackAddToBuddyListConfirmationResponseHandler`      |             |
| 0x48      | 1           | `0x232ce60` | `MediusUniqueCallbackGetPolicyResponseHandler`                       |             |
| 0x49      | 1           | `0x232cf28` | `MediusUniqueCallbackUpdateUserStateHandler`                         |             |
| 0x4a      | 1           | `0x232c658` | `MediusUniqueCallbackErrorMessageHandler`                            |             |
| 0x4d      | 1           | `0x232cf30` | `MediusUniqueCallbackGetAnnouncementsResponseHandler`                |             |
| 0x4f      | 1           | `0x232cf68` | `MediusUniqueCallbackSetGameListFilterResponseHandler0`              |             |
| 0x51      | 1           | `0x232cfa8` | `MediusUniqueCallbackClearGameListFilterResponseHandler`             |             |
| 0x53      | 1           | `0x232cfe0` | `MediusUniqueCallbackGetGameListFilterResponseHandler0`              |             |
| 0x55      | 1           | `0x232d020` | `MediusUniqueCallbackCreateClanResponseHandler`                      |             |
| 0x57      | 1           | `0x232d058` | `MediusUniqueCallbackDisbandClanResponseHandler`                     |             |
| 0x59      | 1           | `0x232d090` | `MediusUniqueCallbackGetClanByIDResponseHandler`                     |             |
| 0x5b      | 1           | `0x232d0c8` | `MediusUniqueCallbackGetClanByNameResponseHandler`                   |             |
| 0x5d      | 1           | `0x232d100` | `MediusUniqueCallbackTransferClanLeadershipResponseHandler`          |             |
| 0x5f      | 1           | `0x232d138` | `MediusUniqueCallbackAddPlayerToClanResponseHandler`                 |             |
| 0x61      | 1           | `0x232d170` | `MediusUniqueCallbackRemovePlayerFromClanResponseHandler`            |             |
| 0x99      | 1           | `0x232d1a8` | `MediusUniqueCallbackInvitePlayerToClanResponseHandler`              |             |
| 0x65      | 1           | `0x232d1e0` | `MediusUniqueCallbackCheckMyClanInvitationsResponseHandler`          |             |
| 0x67      | 1           | `0x232d250` | `MediusUniqueCallbackRespondToClanInvitationResponseHandler`         |             |
| 0x69      | 1           | `0x232d288` | `MediusUniqueCallbackRevokeClanInvitationResponseHandler`            |             |
| 0x6b      | 1           | `0x232d2c0` | `MediusUniqueCallbackRequestClanTeamChallengeResponseHandler`        |             |
| 0x6d      | 1           | `0x232d2f8` | `MediusUniqueCallbackGetMyClanMessagesResponseHandler`               |             |
| 0x6f      | 1           | `0x232d330` | `MediusUniqueCallbackSendClanMessageResponseHandler`                 |             |
| 0x71      | 1           | `0x232d368` | `MediusUniqueCallbackModifyClanMessageResponseHandler`               |             |
| 0x73      | 1           | `0x232d3a0` | `MediusUniqueCallbackDeleteClanMessageResponseHandler`               |             |
| 0x75      | 1           | `0x232d3d8` | `MediusUniqueCallbackRespondToClanTeamChallengeResponseHandler`      |             |
| 0x77      | 1           | `0x232d410` | `MediusUniqueCallbackRevokeClanTeamChallengeResponseHandler`         |             |
| 0x79      | 1           | `0x232d528` | `MediusUniqueCallbackGetClanTeamChallengeHistoryResponseHandler`     |             |
| 0x7b      | 1           | `0x232d218` | `MediusUniqueCallbackGetClanInvitationsSentResponseHandler`          |             |
| 0x7d      | 1           | `0x232d448` | `MediusUniqueCallbackGetMyClansResponseHandler`                      |             |
| 0x7f      | 1           | `0x232d4f0` | `MediusUniqueCallbackGetAllClanMessagesResponseHandler`              |             |
| 0x81      | 1           | `0x232d4b8` | `MediusUniqueCallbackConfirmClanTeamChallengeResponseHandler`        |             |
| 0x83      | 1           | `0x232d480` | `MediusUniqueCallbackGetClanTeamChallengesResponseHandler`           |             |
| 0x85      | 1           | `0x232d560` | `MediusUniqueCallbackUpdateClanStatsResponseHandler`                 |             |
| 0x87      | 1           | `0x232d5d0` | `MediusUniqueCallbackVersionServerResponseHandler`                   |             |
| 0x89      | 1           | `0x232d608` | `MediusUniqueCallbackGetWorldSecurityLevelResponseHandler`           |             |
| 0x8b      | 1           | `0x232d640` | `MediusUniqueCallbackBanPlayerResponseHandler`                       |             |
| 0x8d      | 1           | `0x232d6e8` | `MediusUniqueCallbackGetLocationsResponseHandler`                    |             |
| 0x8f      | 1           | `0x232d720` | `MediusUniqueCallbackPickLocationResponseHandler`                    |             |
| 0x91      | 1           | `0x232d758` | `MediusUniqueCallbackGetClanMemberListResponseHandler`               |             |
| 0x99      | 1           | `0x232d800` | `MediusUniqueCallbackTextFilterResponseHandler`                      |             |
| 0x9a      | 1           | `0x232d838` | `MediusUniqueCallbackReassignGameMediusWorldIDHandler`               |             |
| 0x9c      | 1           | `0x232d870` | `MediusUniqueCallbackGetTotalGamesResponseHandler`                   |             |
| 0x9e      | 1           | `0x232d8a8` | `MediusUniqueCallbackGetTotalChannelsResponseHandler`                |             |
| 0xa0      | 1           | `0x232d8e0` | `MediusUniqueCallbackGetLobbyPlayerNamesResponseHandler`             |             |
| 0xa2      | 1           | `0x232d918` | `MediusUniqueCallbackGetTotalUsersResponseHandler`                   |             |
| 0xa4      | 1           | `0x232d950` | `MediusUniqueCallbackSetLocalizationParamsResponseHandler`           |             |
| 0xa6      | 1           | `0x232dc98` | `MediusUniqueCallbackFileCreateResponseHandler`                      |             |
| 0xa8      | 1           | `0x232dcd0` | `MediusUniqueCallbackFileUploadFromClientResponseHandler`            |             |
| 0xa9      | 1           | `0x232dcd8` | `MediusUniqueCallbackFileUploadResponseHandler`                      |             |
| 0xab      | 1           | `0x232ddb0` | `MediusUniqueCallbackFileCloseResponseHandler`                       |             |
| 0xad      | 1           | `0x232dde8` | `MediusUniqueCallbackFileDownloadResponseHandler`                    |             |
| 0xaf      | 1           | `0x232de20` | `MediusUniqueCallbackFileDownloadStreamResponseHandler`              |             |
| 0xb1      | 1           | `0x232de58` | `MediusUniqueCallbackFileDeleteResponseHandler`                      |             |
| 0xb3      | 1           | `0x232de90` | `MediusUniqueCallbackFileListFilesResponseHandler`                   |             |
| 0xb5      | 1           | `0x232dec8` | `MediusUniqueCallbackFileUpdateAttributesResponseHandler`            |             |
| 0xb7      | 1           | `0x232df00` | `MediusUniqueCallbackFileGetAttributesResponseHandler`               |             |
| 0xb9      | 1           | `0x232df38` | `MediusUniqueCallbackFileUpdateMetaDataResponseHandler`              |             |
| 0xbb      | 1           | `0x232df70` | `MediusUniqueCallbackFileGetMetaDataResponseHandler`                 |             |
| 0xbd      | 1           | `0x232dfa8` | `MediusUniqueCallbackFileSearchByMetaDataResponseHandler`            |             |
| 0xbf      | 1           | `0x232dfe0` | `MediusUniqueCallbackFileCancelOperationResponseHandler`             |             |
| 0xc1      | 1           | `0x232cdb8` | `MediusUniqueCallbackGetIgnoreListResponseHandler`                   |             |
| 0xc3      | 1           | `0x232cdf0` | `MediusUniqueCallbackAddToIgnoreListResponseHandler`                 |             |
| 0xc5      | 1           | `0x232ce28` | `MediusUniqueCallbackRemoveFromIgnoreListResponseHandler`            |             |
| 0x199     | 1           | `0x232d988` | `MediusUniqueCallbackSetMessageAsReadResponseHandler`                |             |
| 0xc9      | 1           | `0x232e018` | `MediusUniqueCallbackUniverseNewsHandler`                            |             |
| 0xca      | 1           | `0x232e070` | `MediusUniqueCallbackUniverseStatusListHandler`                      |             |
| 0xcd      | 1           | `0x232d790` | `MediusUniqueCallbackLadderPositionFastResponseHandler`              |             |
| 0xcf      | 1           | `0x232dbb8` | `MediusUniqueCallbackUpdateLadderStatsResponseHandler`               |             |
| 0xd3      | 1           | `0x232d9c0` | `MediusUniqueCallbackClanLadderListResponseHandler`                  |             |
| 0xd5      | 1           | `0x232d9f8` | `MediusUniqueCallbackClanLadderPositionResponseHandler`              |             |
| 0xd7      | 1           | `0x232da30` | `MediusUniqueCallbackGetBuddyList_ExtraInfoResponseHandler`          |             |
| 0xd9      | 1           | `0x232da68` | `MediusUniqueCallbackGetTotalRankingsResponseHandler`                |             |
| 0xdb      | 1           | `0x232dad8` | `MediusUniqueCallbackGetClanMemberList_ExtraInfoResponseHandler`     |             |
| 0xdd      | 1           | `0x232daa0` | `MediusUniqueCallbackGetLobbyPlayerNames_ExtraInfoResponseHandler`   |             |
| 0x38      | 4           | `0x232db10` | `MediusUniqueCallbackGameList_ExtraInfoResponseHandler`              |             |
| 0xed      | 1           | `0x232db48` | `MediusUniqueCallbackChannelList_ExtraInfoResponseHandler`           |             |
| 0xf0      | 1           | `0x232db80` | `MediusUniqueCallbackLadderList_ExtraInfoResponseHandler`            |             |
| 0xf2      | 1           | `0x232dc60` | `MediusUniqueCallbackLadderPosition_ExtraInfoResponseHandler`        |             |
| 0xf6      | 1           | `0x232e728` | `MediusUtilAddLobbyWorldResponseHandler`                             |             |
| 0xf8      | 1           | `0x232e760` | `MediusUtilAddGameWorldResponseHandler`                              |             |
| 0xfa      | 1           | `0x232e798` | `MediusUtilUpdateLobbyWorldResponseHandler`                          |             |
| 0xfc      | 1           | `0x232e7d0` | `MediusUtilUpdateGameWorldResponseHandler`                           |             |
| 0x2       | 4           | `0x232e6f0` | `MediusUtilGetServerVersionResponseHandler`                          |             |
| 0x4       | 4           | `0x232e078` | `MediusUniqueCallbackUniverseStatusList_ExtraInfoHandler`            |             |
| 0x6       | 4           | `0x232cd78` | `MediusUniqueCallbackAddToBuddyListFwdConfirmationRequestHandler`    |             |
| 0x7       | 4           | `0x232cdb0` | `MediusUniqueCallbackAddToBuddyListFwdConfirmationResponseHandler`   |             |
| 0x9       | 4           | `0x232e840` | `MediusUniqueCallbackGetBuddyInvitationsResponseHandler`             |             |
| 0x10      | 4           | `0x232c750` | `MediusUniqueCallbackDnasSignaturePostHandler`                       |             |
| 0xc       | 4           | `0x232dbf0` | `MediusUniqueCallbackUpdateLadderStatsWideResponseHandler`           |             |
| 0xe       | 4           | `0x232dc28` | `MediusUniqueCallbackGetLadderStatsWideResponseHandler`              |             |
| 0x10      | 4           | `0x232e808` | `MediusUtilEventMsgHandler`                                          |             |
| 0x11      | 4           | `0x232e110` | `MediusUniqueCallbackUniverseVariableInfoHandler`                    |             |
| 0x13      | 4           | `0x232e878` | `MediusUniqueCallbackSetLobbyWorldFilterResponseHandler`             |             |
| 0x16      | 4           | `0x232cc58` | `MediusUniqueCallbackBinaryMessageHandler`                           |             |
| 0x17      | 4           | `0x232cc60` | `MediusUniqueCallbackBinaryFwdMessageHandler`                        |             |
| 0x19      | 4           | `0x232e8f0` | `MediusUniqueCallbackPostDebugInfoResponseHandler`                   |             |
| 0x1b      | 4           | `0x232e938` | `MediusUniqueCallbackUpdateClanLadderStatsWide_DeltaResponseHandler` |             |
| 0x1e      | 4           | `0x232e080` | `MediusUniqueCallbackUniverseSvoURLHandler`                          |             |
| 0x23      | 4           | `0x232cc18` | `MediusUniqueCallbackGenericChatMessageHandler`                      |             |
| 0x24      | 4           | `0x232cc20` | `MediusUniqueCallbackGenericChatFwdMessageHandler`                   |             |
| 0x26      | 4           | `0x232d7c8` | `MediusUniqueCallbackGenericChatSetFilterResponseHandler`            |             |
| 0x29      | 4           | `0x232e970` | `MediusUniqueCallbackTokenResponseHandler`                           |             |
| 0x2b      | 4           | `0x232e9a8` | `MediusUniqueCallbackGetServerTimeResponseHandler`                   |             |
| 0x32      | 4           | `0x232cfe8` | `MediusUniqueCallbackGetGameListFilterResponseHandler`               |             |
| 0x34      | 4           | `0x232cf70` | `MediusUniqueCallbackSetGameListFilterResponseHandler`               |             |
| 0x2e      | 4           | `0x232e9e0` | `MediusUniqueCallbackSetAutoChatHistoryResponseHandler`              |             |

List of all packet callbacks (not in order):

<details open>
<summary><code>MediusUniqueCallbackAccountDeleteResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAccountGetIDResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAccountGetProfileResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAccountLoginResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAccountLogoutResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAccountRegistrationResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAccountUpdatePasswordResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAccountUpdateProfileResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAccountUpdateStatsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAddPlayerToClanResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAddToBuddyListConfirmationResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAddToBuddyListFwdConfirmationRequestHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAddToBuddyListFwdConfirmationResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAddToBuddyListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAddToIgnoreListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackAnonymousLoginResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBanPlayerResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingDetailRequestHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingDetailResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingInfoRequestHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingListRequestHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingLoginRequestHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingLoginResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingTunnelRequestHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBillingTunnelResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBinaryFwdMessageHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackBinaryMessageHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackChannelInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackChannelList_ExtraInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackChannelListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackCheckMyClanInvitationsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackClanLadderListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackClanLadderPositionResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackClearGameListFilterResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackConfirmClanTeamChallengeResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackCreateChannelResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackCreateClanResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackCreateGameResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackDeleteClanMessageResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackDisbandClanResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackDnasSignaturePostHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackEndGameReportHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackErrorMessageHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileCancelOperationResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileCloseResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileCreateResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileDeleteResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileDownloadResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileDownloadStreamResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileGetAttributesResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileGetMetaDataResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileListFilesResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileSearchByMetaDataResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileUpdateAttributesResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileUpdateMetaDataResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileUploadFromClientResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFileUploadResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFindPlayerResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackFindWorldByNameResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGameInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGameList_ExtraInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGameListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGameWorldPlayerListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGenericChatFwdMessageHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGenericChatMessageHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGenericChatSetFilterResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetAllClanMessagesResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetAnnouncementsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetBuddyInvitationsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetBuddyList_ExtraInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetBuddyListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetClanByIDResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetClanByNameResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetClanInvitationsSentResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetClanMemberList_ExtraInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetClanMemberListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetClanTeamChallengeHistoryResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetClanTeamChallengesResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetGameListFilterResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetGameListFilterResponseHandler0</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetIgnoreListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetLadderStatsWideResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetLobbyPlayerNames_ExtraInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetLobbyPlayerNamesResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetLocationsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetMyClanMessagesResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetMyClansResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetMyIPResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetPolicyResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetServerTimeResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetTotalChannelsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetTotalGamesResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetTotalRankingsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetTotalUsersResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackGetWorldSecurityLevelResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackInvitePlayerToClanResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackJoinChannelFwdResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackJoinChannelResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackJoinGameResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackLadderList_ExtraInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackLadderPosition_ExtraInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackLadderPositionFastResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackLobbyWorldPlayerListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackModifyClanMessageResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackPickLocationResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackPlayerInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackPlayerReportHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackPostDebugInfoResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackProductPurchaseRequestHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackProductPurchaseResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackReassignGameMediusWorldIDHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackRemoveFromBuddyListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackRemoveFromIgnoreListResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackRemovePlayerFromClanResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackRequestClanTeamChallengeResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackRespondToClanInvitationResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackRespondToClanTeamChallengeResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackRevokeClanInvitationResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackRevokeClanTeamChallengeResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackSendClanMessageResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackSessionBeginResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackSessionEndResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackSetAutoChatHistoryResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackSetGameListFilterResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackSetGameListFilterResponseHandler0</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackSetLobbyWorldFilterResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackSetLocalizationParamsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackSetMessageAsReadResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackTextFilterResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackTokenResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackTransferClanLeadershipResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUniverseNewsHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUniverseStatusList_ExtraInfoHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUniverseStatusListHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUniverseSvoURLHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUniverseVariableInfoHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUpdateClanLadderStatsWide_DeltaResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUpdateClanStatsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUpdateLadderStatsResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUpdateLadderStatsWideResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackUpdateUserStateHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackVersionServerResponseHandler</code></summary>
</details open>

<details open>
<summary><code>MediusUniqueCallbackWorldReportHandler</code></summary>
</details open>