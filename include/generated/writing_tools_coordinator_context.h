#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class UUID;

    /**
     * @brief C++ handle for the Objective-C class `NSWritingToolsCoordinatorContext` (AppKit).
     * @details A data object that you use to share your custom view’s text with Writing Tools. At the start of every Writing Tools operation, you create one or more 'NSWritingToolsCoordinator.Context' objects with a copy of the text you want Writing Tools to evaluate. Each Writing Tools operation starts with a call to the ''NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(:requestsContextsFor:completion:)'' method of your ''NSWritingToolsCoordinator/Delegate'' object. Use the parameters of that method to determine how much of your view’s text to provide. For some operations, Writing Tools asks for all of your view’s text, but in others it asks for only a portion of the text. When Writing Tools finishes its evaluation, it reports changes back to your delegate relative to the context objects you provided. When Writing Tools asks for your view’s text, create one or more 'NSWritingToolsCoordinator.Context' objects with the requested content. If your view contains only one text storage object, create only one context object for the request. However, if you use multiple text storage objects to manage different parts of your view’s content, you might need to create multiple context objects. The actual number depends on how much of your text Writing Tools asks for. For example, when Writing Tools asks for all of your view’s content, you return one context object for each text storage object in your view. However, if Writing Tools asks for the current selection, and one text storage object contains all of the selected text, you create only one context object for the content. Writing Tools uses your context objects as the starting point for its evaluations, and as a reference point for any changes. Because Writing Tools doesn’t know anything about your view or its content, it makes suggestions only relative to your context objects. It’s your responsibility to take those suggestions and incorporate them back into your view’s text storage. In some cases, you might need to store additional information to update your storage correctly. For example, you might need to store, and update as needed, the offset from the start of your document to the start of the text in your context object. When Writing Tools asks for the currently selected text in your view, include some of the surrounding text in your context object as well. Supply a string that includes the selection and any text up to the nearest paragraph boundary. When creating your context object, specify a range value that represents the portion of that string that corresponds to the text selection. Providing some additional text in your context object can help Writing Tools improve its evaluation of your content. Writing Tools uses the ''resolvedRange'' property of your context object to indicate what text it considered. If your context object includes text that you don’t want Writing Tools to evaluate, add the 'excludeFromWritingTools' attribute to the corresponding characters of your \<doc://com.apple.documentation/documentation/foundation/nsattributedstring> object. You might add this attribute if the text string includes a code listing or readonly content that you don’t want Writing Tools to change.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::WritingToolsCoordinatorContext writing_tools_coordinator_context(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nswritingtoolscoordinatorcontext
     */
    class WritingToolsCoordinatorContext : public Object
    {
    public:
        /// @brief Creates a new `NSWritingToolsCoordinatorContext` instance and returns a handle to it.
        explicit WritingToolsCoordinatorContext(const AttributedString& attributed_string, const Range& range);
        WritingToolsCoordinatorContext();
        /// @brief Creates a null handle that refers to no native object.
        WritingToolsCoordinatorContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit WritingToolsCoordinatorContext(Adopt adopt);
        /**
     * @brief Returns the `attributedString` property of `NSWritingToolsCoordinatorContext`.
     * @details The portion of your view’s text to evaluate. The ''NSWritingToolsCoordinator/Context'' object initializes the value of this property at creation time and doesn’t change it during the course of an operation. Instead, it suggests changes to the text in the indicated range and reports those changes to your ''NSWritingToolsCoordinator/Delegate'' object. Use the methods of your delegate object to integrate those changes back into your view’s text storage. It’s your responsibility to track the location of this text in your view’s text storage object. When Writing Tools reports changes, it provides range values relative to this string. If you initialize this property with a subset of your view’s content, you must adjust any ranges that Writing Tools provides to get the correct location in your text storage.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string() const;
        /**
     * @brief Returns the `identifier` property of `NSWritingToolsCoordinatorContext`.
     * @details The unique identifier of the context object. The ''NSWritingToolsCoordinator/Context'' object initializes the value of this property at creation time. Use this value to identify the context object within your app.
     * @return The converted Objective-C result.
     */
        UUID identifier() const;
        /**
     * @brief Returns the `range` property of `NSWritingToolsCoordinatorContext`.
     * @details The unique identifier of the context object. The ''NSWritingToolsCoordinator/Context'' object initializes the value of this property at creation time. Use this value to identify the context object within your app.
     * @return The converted Objective-C result.
     */
        Range range() const;
        /**
     * @brief Returns the `resolvedRange` property of `NSWritingToolsCoordinatorContext`.
     * @details The actual range of text that Writing Tools might change, which can be different than the range of text you supplied. After analyzing the text in your context object, Writing Tools sets this property to the portion of ''attributedString'' it might modify. Initially, this property has a location of \<doc://com.apple.documentation/documentation/foundation/nsnotfound> and a length of '0', but Writing Tools updates those values before making any changes to the text. While the Writing Tools operation is active, make sure Writing Tools has exclusive access to the text in this range. Your ''NSWritingToolsCoordinator/Delegate'' object can make changes to the text as part of incorporating Writing Tools results, but don’t allow changes to come from other sources. For example, don’t let someone edit the text in this range directly until Writing Tools finishes.
     * @return The converted Objective-C result.
     */
        Range resolved_range() const;
    };
}
