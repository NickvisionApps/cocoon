#include "generated/controller.h"
#include "internal.h"

namespace cocoon
{
    Controller::Controller() : Controller(Adopt{cocoon::internal::retain([[::NSController alloc] init])})
    {
    }

    Controller::Controller(std::nullptr_t) : Object(nullptr)
    {
    }

    Controller::Controller(Adopt adopt) : Object(adopt)
    {
    }

    bool Controller::commit_editing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSController>(this) commitEditing]);
    }

    void Controller::commit_editing_with_delegate(const Object& delegate, const std::string& did_commit_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSController>(this) commitEditingWithDelegate:cocoon::internal::native_id(delegate) didCommitSelector:NSSelectorFromString(cocoon::internal::to(did_commit_selector)) contextInfo:context_info];
    }

    void Controller::discard_editing() const
    {
        [cocoon::internal::ns<::NSController>(this) discardEditing];
    }

    void Controller::object_did_begin_editing(const Object& editor) const
    {
        [cocoon::internal::ns<::NSController>(this) objectDidBeginEditing:cocoon::internal::native_id(editor)];
    }

    void Controller::object_did_end_editing(const Object& editor) const
    {
        [cocoon::internal::ns<::NSController>(this) objectDidEndEditing:cocoon::internal::native_id(editor)];
    }

    bool Controller::is_editing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSController>(this) isEditing]);
    }
}
