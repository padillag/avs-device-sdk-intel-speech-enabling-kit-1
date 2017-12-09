/*
 * TestableAttachmentManager.h
 *
 * Copyright 2017 Amazon.com, Inc. or its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ALEXA_CLIENT_SDK_ACL_TEST_TRANSPORT_COMMON_TESTABLEATTACHMENTMANAGER_H_
#define ALEXA_CLIENT_SDK_ACL_TEST_TRANSPORT_COMMON_TESTABLEATTACHMENTMANAGER_H_

#include <AVSCommon/AVS/Attachment/AttachmentManager.h>

namespace alexaClientSDK {
namespace acl {
namespace test {

/**
 * A version of the Decorator Pattern, this class allows us to return a special AttachmentWriter class to
 * calling code, while routing all other functionality to a normal encapsulated AttachmentManager object.
 */
class TestableAttachmentManager : public avsCommon::avs::attachment::AttachmentManager {
public:
    /**
     * Constructor.
     */
    TestableAttachmentManager();

    std::string generateAttachmentId(const std::string& contextId, const std::string& contentId) const override;

    bool setAttachmentTimeoutMinutes(std::chrono::minutes timeoutMinutes) override;

    std::unique_ptr<avsCommon::avs::attachment::AttachmentWriter> createWriter(
        const std::string& attachmentId) override;

    std::unique_ptr<avsCommon::avs::attachment::AttachmentReader> createReader(
        const std::string& attachmentId,
        avsCommon::avs::attachment::AttachmentReader::Policy policy) override;

private:
    /// The real AttachmentManager that most functionality routes to.
    std::unique_ptr<avsCommon::avs::attachment::AttachmentManager> m_manager;
};

}  // namespace test
}  // namespace acl
}  // namespace alexaClientSDK

#endif  // ALEXA_CLIENT_SDK_ACL_TEST_TRANSPORT_COMMON_TESTABLEATTACHMENTMANAGER_H_
