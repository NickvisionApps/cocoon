#include "generated/predicate_editor.h"
#include "internal.h"

namespace cocoon
{
    PredicateEditor::PredicateEditor() : PredicateEditor(Adopt{cocoon::internal::retain([[::NSPredicateEditor alloc] init])})
    {
        RuleEditor::install_delegate_delegate_(handle());
    }

    PredicateEditor::PredicateEditor(std::nullptr_t) : RuleEditor(nullptr)
    {
    }

    PredicateEditor::PredicateEditor(Adopt adopt) : RuleEditor(adopt)
    {
    }

    std::vector<PredicateEditorRowTemplate> PredicateEditor::row_templates() const
    {
        return cocoon::internal::from_array<PredicateEditorRowTemplate>([cocoon::internal::ns<::NSPredicateEditor>(this) rowTemplates], [](id e) -> PredicateEditorRowTemplate
                                                          {
                                                              return cocoon::internal::wrap<PredicateEditorRowTemplate>((::NSPredicateEditorRowTemplate*)e);
                                                          });
    }

    void PredicateEditor::set_row_templates(const std::vector<PredicateEditorRowTemplate>& value) const
    {
        [cocoon::internal::ns<::NSPredicateEditor>(this) setRowTemplates:cocoon::internal::to_array(value, [](const PredicateEditorRowTemplate& e) -> id
                                                                        {
                                                                            return cocoon::internal::native<::NSPredicateEditorRowTemplate>(e);
                                                                        })];
    }
}
